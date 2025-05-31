import { Link } from 'react-router-dom';

export default function NotFound() {
    return (
        <div className="flex flex-col items-center justify-center min-h-screen px-6 text-center bg-gray-50">
            <h1 className="text-6xl font-extrabold text-blue-600 animate-pulse mb-4">404</h1>
            <h2 className="text-2xl font-semibold text-gray-800 mb-2">Strona nie została znaleziona</h2>
            <p className="text-gray-600 mb-6 max-w-md">
                Wygląda na to, że adres jest nieprawidłowy lub strona została usunięta.
                Sprawdź adres lub wróć na stronę główną.
            </p>
            <Link
                to="/"
                className="bg-blue-600 text-white px-6 py-3 rounded-lg shadow hover:bg-blue-700 transition"
            >
                Wróć na stronę główną
            </Link>
        </div>
    );
}
