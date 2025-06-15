import { BrowserRouter, Routes, Route, useLocation } from 'react-router-dom';
import Layout from './components/Layout';
import Home from './pages/Home';
import Contact from './pages/Contact';
import Offer from './pages/Offer';
import Pricing from './pages/Pricing';
import Services from './pages/Services';
import Blog from './pages/Blog';
import Reviews from './pages/Reviews';
import NotFound from './pages/NotFound';
import ThemeProvider from './context/ThemeContext';
import { AnimatePresence } from 'framer-motion';

function AnimatedRoutes() {
    const location = useLocation();

    return (
        <AnimatePresence mode="wait">
            <Routes location={location} key={location.pathname}>
                <Route path="/" element={<Home />} />
                <Route path="/offer" element={<Offer />} />
                <Route path="/contact" element={<Contact />} />
                <Route path="/pricing" element={<Pricing />} />
                <Route path="/services" element={<Services />} />
                <Route path="/blog" element={<Blog />} />
                <Route path="/reviews" element={<Reviews />} />
                <Route path="*" element={<NotFound />} />
            </Routes>
        </AnimatePresence>
    );
}

export default function App() {
    return (
        <ThemeProvider>
            <BrowserRouter>
                <Layout>
                    <AnimatedRoutes />
                </Layout>
            </BrowserRouter>
        </ThemeProvider>
    );
}
