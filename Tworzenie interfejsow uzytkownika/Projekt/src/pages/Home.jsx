import { Link } from 'react-router-dom';
import illustration from '../assets/illustration.svg';

export default function Home() {
    return (
        <div className="py-16 px-4 space-y-24 max-w-screen-lg mx-auto">
            <section className="space-y-6 text-center animate-fade-in-up">
                <h2 className="text-2xl sm:text-3xl md:text-5xl font-bold text-gray-800 leading-tight transition-all duration-700">
                    Zarządzaj częściami samochodowymi{' '}
                    <span className="text-blue-600">łatwiej niż kiedykolwiek!</span>
                </h2>
                <p className="text-md sm:text-lg md:text-xl text-gray-500 max-w-3xl mx-auto transition-opacity duration-700 delay-100">
                    Pełna kontrola magazynu części samochodowych w jednym, przejrzystym miejscu.
                </p>
                <div className="flex flex-col sm:flex-row justify-center gap-4 items-center">
                    <Link
                        to="/offer"
                        className="bg-blue-600 hover:bg-blue-700 text-white px-6 py-3 rounded-lg shadow-md transition-transform duration-300 hover:scale-105"
                    >
                        Zobacz ofertę
                    </Link>
                    <Link
                        to="/contact"
                        className="bg-green-600 hover:bg-green-700 text-white px-6 py-3 rounded-lg shadow-md transition-transform duration-300 hover:scale-105"
                    >
                        Skontaktuj się z nami
                    </Link>
                </div>
            </section>

            <section className="bg-gray-100 py-12 rounded-lg shadow-inner px-4">
                <div className="grid grid-cols-1 md:grid-cols-3 gap-8 justify-center">
                    {[
                        {
                            icon: '⚙️',
                            title: 'Zarządzanie magazynem',
                            desc: 'Pełna kontrola nad stanem części samochodowych.'
                        },
                        {
                            icon: '📦',
                            title: 'Śledzenie stanów',
                            desc: 'Bądź na bieżąco z poziomem zapasów i stanem minimalnym.'
                        },
                        {
                            icon: '🧾',
                            title: 'Szybkie dodawanie',
                            desc: 'Dodawaj nowe części w kilka sekund.'
                        }
                    ].map((item) => (
                        <div
                            key={item.title}
                            className="bg-white p-6 rounded-lg shadow hover:shadow-xl transition-all transform hover:scale-105 duration-300 text-center"
                        >
                            <div className="text-4xl mb-2">{item.icon}</div>
                            <h3 className="text-lg font-semibold mb-1">{item.title}</h3>
                            <p className="text-gray-600 text-sm">{item.desc}</p>
                        </div>
                    ))}
                </div>
            </section>

            <section className="flex flex-col md:flex-row items-center gap-8 bg-gradient-to-r from-blue-50 to-blue-100 rounded-xl p-6 md:p-10 shadow-lg">
                <div className="w-full md:w-1/2 flex justify-center bg-white md:bg-gray-100 p-4 md:p-6 rounded-lg shadow animate-fade-in">
                    <img
                        src={illustration}
                        alt="Ilustracja"
                        className="max-w-full h-auto transform hover:scale-105 transition-transform duration-500"
                    />
                </div>
                <div className="w-full md:w-1/2 text-left space-y-4">
                    <h3 className="text-2xl md:text-3xl font-bold text-gray-800">Nowoczesny interfejs</h3>
                    <p className="text-gray-600 text-sm sm:text-base">
                        Nasz system został zaprojektowany z myślą o prostocie i szybkości obsługi. Dzięki przejrzystemu interfejsowi znajdziesz potrzebne informacje błyskawicznie.
                    </p>
                </div>
            </section>

            <section className="bg-gradient-to-r from-blue-500 to-indigo-500 py-10 rounded-lg shadow-lg text-white text-center space-y-4 animate-bounce-slow">
                <h4 className="text-xl sm:text-2xl font-semibold">Gotowy, aby zacząć?</h4>
                <Link
                    to="/pricing"
                    className="inline-block bg-white text-blue-600 px-6 py-3 rounded-lg shadow-md font-semibold hover:scale-105 transition-transform duration-300"
                >
                    Zobacz nasze plany
                </Link>
            </section>
        </div>
    );
}
